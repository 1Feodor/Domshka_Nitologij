#include <map>
#include <string>
#include <iostream>
#include <Windows.h>



class VeryHeavyDatabase 
{
public:
    std::string get_data(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};

class CacheProxyDB : VeryHeavyDatabase 
{
    std::map<std::string, std::string> cache_;
    std::unique_ptr<VeryHeavyDatabase> real_DB_;
public:
    explicit CacheProxyDB(std::unique_ptr<VeryHeavyDatabase> real_object) : real_DB_{ move(real_object) } {}
    std::string get_data(const std::string& key) noexcept 
    {
        if (cache_.find(key) == cache_.end()) 
        {
            std::cout << "Get from real object\n";
            cache_[key] = real_DB_->get_data(key);
        }
        else 
        {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }
};

class TestDB : VeryHeavyDatabase {
    std::unique_ptr<VeryHeavyDatabase> real_DB_;
public:
    explicit TestDB(std::unique_ptr<VeryHeavyDatabase> real_object) : real_DB_{ move(real_object) } {}
    std::string get_data(const std::string& key) noexcept {
        return "test_data" + key;
    }
};

class OneShotDB : VeryHeavyDatabase {
    std::unique_ptr<VeryHeavyDatabase> real_DB_;
    size_t shots;
public:
    explicit OneShotDB(std::unique_ptr<VeryHeavyDatabase> real_object, size_t shots = 1)
        : real_DB_{ move(real_object) }, shots{ shots } {}
    std::string get_data(const std::string& key) noexcept
    {
        if (this->shots)
        {
            --this->shots;
            std::cout << "Get from real object\n";
            return real_DB_->get_data(key);
        }
        return "error\n";
    }

};

std::unique_ptr<CacheProxyDB> init_cache()
{
    auto original_DB = std::make_unique<VeryHeavyDatabase>();
    return std::make_unique<CacheProxyDB>(move(original_DB));
}

std::unique_ptr<TestDB> init_test()
{
    auto original_DB = std::make_unique<VeryHeavyDatabase>();
    return std::make_unique<TestDB>(move(original_DB));
}

std::unique_ptr<OneShotDB> init_limit()
{
    auto original_DB = std::make_unique<VeryHeavyDatabase>();
    return std::make_unique<OneShotDB>(move(original_DB), 2);
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

    auto DB{ init_cache() };
    std::cout << DB->get_data("key1") << std::endl;
    std::cout << DB->get_data("key1") << std::endl;
    std::cout << DB->get_data("key2") << std::endl;
    std::cout << std::endl;

    auto DB_test{ init_test() };
    std::cout << DB_test->get_data("key1") << std::endl;
    std::cout << DB_test->get_data("key1") << std::endl;
    std::cout << DB_test->get_data("key2") << std::endl;
	std::cout << std::endl;

    auto DB_limit{ init_limit() };
    std::cout << DB_limit->get_data("key1") << std::endl;
    std::cout << DB_limit->get_data("key1") << std::endl;
    std::cout << DB_limit->get_data("key2") << std::endl;
    std::cout << std::endl;
	
	return 0;
}