#include <iostream>
#include <list>
#include <vector>
#include <string>

// A simple pair structure
template <typename K, typename V>
struct MyPair {
    K key;
    V value;
    MyPair(const K& k, const V& v) : key(k), value(v) {}
};

// A simple hash function
template <typename K>
struct MyHash {
    size_t operator()(const K& key) const {
        size_t hash = 0;
        for (const char& c : key) {
            hash = hash * 31 + c;
        }
        return hash;
    }
};

// Specialization of hash function for integer keys
template <>
struct MyHash<int> {
    size_t operator()(const int& key) const {
        return key;
    }
};

// Specialization of hash function for float keys
template <>
struct MyHash<float> {
    size_t operator()(const float& key) const {
        return std::hash<float>{}(key);
    }
};

// Specialization of hash function for double keys
template <>
struct MyHash<double> {
    size_t operator()(const double& key) const {
        return std::hash<double>{}(key);
    }
};

// Specialization of hash function for custom object keys
template <typename T>
struct MyHash<T*> {
    size_t operator()(const T* key) const {
        return reinterpret_cast<size_t>(key);
    }
};

template <typename K, typename V>
class HashMap {
private:
    std::vector<std::list<MyPair<K, V>>> table;
    size_t num_elements;
    const float load_factor = 0.75;

    size_t hashFunction(const K& key) const {
        MyHash<K> hash_func;
        return hash_func(key) % table.size();
    }

    void rehash() {
        std::vector<std::list<MyPair<K, V>>> old_table = table;
        table.resize(table.size() * 2);
        for (auto& bucket : table) {
            bucket.clear();
        }
        num_elements = 0;
        for (const auto& bucket : old_table) {
            for (const auto& item : bucket) {
                insert(item.key, item.value);
            }
        }
    }

public:
    HashMap(size_t initial_size = 16) : table(initial_size), num_elements(0) {}

    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key);
        for (auto& item : table[index]) {
            if (item.key == key) {
                item.value = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
        ++num_elements;

        if (static_cast<float>(num_elements) / table.size() > load_factor) {
            rehash();
        }
    }

    bool get(const K& key, V& value) const {
        size_t index = hashFunction(key);
        for (const auto& item : table[index]) {
            if (item.key == key) {
                value = item.value;
                return true;
            }
        }
        return false;
    }

    bool remove(const K& key) {
        size_t index = hashFunction(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                --num_elements;
                return true;
            }
        }
        return false;
    }

    bool contains(const K& key) const {
        size_t index = hashFunction(key);
        for (const auto& item : table[index]) {
            if (item.key == key) {
                return true;
            }
        }
        return false;
    }

    size_t size() const {
        return num_elements;
    }

    void printHashMap() const {
        for (size_t i = 0; i < table.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& item : table[i]) {
                std::cout << "{" << item.key << ": " << item.value << "} ";
            }
            std::cout << std::endl;
        }
    }
};

// CustomClass definition
class CustomClass {
public:
    int data;
    CustomClass(int d) : data(d) {}
    bool operator==(const CustomClass& other) const {
        return data == other.data;
    }

    friend std::ostream& operator<<(std::ostream& os, const CustomClass& obj) {
        os << obj.data;
        return os;
    }
};

// Specialization of hash function for CustomClass
template <>
struct MyHash<CustomClass> {
    size_t operator()(const CustomClass& key) const {
        return std::hash<int>{}(key.data);
    }
};

int main() {
    // Example with integers
    HashMap<int, std::string> intMap;
    intMap.insert(1, "one");
    intMap.insert(2, "two");
    intMap.insert(3, "three");

    std::cout << "Integer HashMap contents:\n";
    intMap.printHashMap();

    std::string value;
    if (intMap.get(2, value)) {
        std::cout << "\nValue for key 2: " << value << std::endl;
    } else {
        std::cout << "\nKey 2 not found." << std::endl;
    }

    // Example with strings
    HashMap<std::string, int> strMap;
    strMap.insert("one", 1);
    strMap.insert("two", 2);
    strMap.insert("three", 3);

    std::cout << "\nString HashMap contents:\n";
    strMap.printHashMap();

    int intValue;
    if (strMap.get("three", intValue)) {
        std::cout << "\nValue for key 'three': " << intValue << std::endl;
    } else {
        std::cout << "\nKey 'three' not found." << std::endl;
    }

    // Example with custom objects
    HashMap<CustomClass, std::string> customMap;
    customMap.insert(CustomClass(1), "custom_one");
    customMap.insert(CustomClass(2), "custom_two");
    customMap.insert(CustomClass(3), "custom_three");

    std::cout << "\nCustomClass HashMap contents:\n";
    customMap.printHashMap();

    std::string customValue;
    if (customMap.get(CustomClass(2), customValue)) {
        std::cout << "\nValue for CustomClass key 2: " << customValue << std::endl;
    } else {
        std::cout << "\nCustomClass key 2 not found." << std::endl;
    }

    return 0;
}
