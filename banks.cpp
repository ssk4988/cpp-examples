#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Bank1
{
public:
    using id = std::string;
    using money = double;
    std::map<id, money> balances;
    static constexpr money min_deposit = 20, max_deposit = 5000;

    void deposit(id account, money amount)
    {
        if (!balances.count(account))
        {
            throw std::invalid_argument("account not found");
        }
        if (amount < min_deposit || amount > max_deposit)
        {
            throw std::invalid_argument("invalid deposit amount");
        }

        balances[account] += amount;
    }

    void create(id account)
    {
        if (balances.count(account))
        {
            throw std::invalid_argument("account already exists");
        }

        balances[account] = 0;
    }

    money get_balance(id account)
    {
        if (!balances.count(account))
        {
            throw std::invalid_argument("account not found");
        }
        return balances[account];
    }

    void withdraw(id account, money amount)
    {
        if (!balances.count(account))
        {
            throw std::invalid_argument("account not found");
        }
        if (amount < 0 || amount > balances[account])
        {
            throw std::invalid_argument("invalid withdraw amount");
        }
        balances[account] -= amount;
    }
};

class Bank2
{
public:
    using id = std::string;
    using money = int;
    std::vector<id> accounts;
    std::vector<money> balances;

    money deposit(id account, money amount)
    {
        std::vector<Bank2::id>::iterator it = std::find(accounts.begin(), accounts.end(), account);
        if (it == accounts.end())
            return -1;
        int idx = it - accounts.begin();
        if (amount < 0)
        {
            return -2;
        }
        balances[idx] += amount;
        return balances[idx];
    }

    money create(id account)
    {
        std::vector<Bank2::id>::iterator it = std::find(accounts.begin(), accounts.end(), account);
        if (it != accounts.end())
            return -3;
        balances.push_back(0);
        accounts.push_back(account);
        return 0;
    }

    money withdraw(id account, money amount)
    {
        std::vector<Bank2::id>::iterator it = std::find(accounts.begin(), accounts.end(), account);
        if (it == accounts.end())
            return -1;
        int idx = it - accounts.begin();
        if (amount < 0 || amount > balances[idx])
        {
            return -4;
        }
        balances[idx] -= amount;
        return balances[idx];
    }
};

Bank1 bank1;
Bank2 bank2;

class Bank3
{
    using id = std::string;
    int bankType(id account)
    {
        std::vector<Bank2::id>::iterator it = std::find(bank2.accounts.begin(), bank2.accounts.end(), account);
        if (it != bank2.accounts.end())
            return 2;
        if (bank1.balances.count(account))
            return 1;
        return 0;
    }
    void bank2Error(int errorCode)
    {
        switch (errorCode)
        {
        case -1:
            throw std::invalid_argument("account not found");
        case -2:
            throw std::invalid_argument("can't deposit a negative amount");
        case -3:
            throw std::invalid_argument("account already exists");
        case -4:
            throw std::invalid_argument("invalid withdrawal amount");
        }
    }
    void deposit(id account, int amount)
    {
        int bank = bankType(account);
        switch (bank)
        {
        case 1:
            bank1.deposit(account, amount);
            break;
        case 2:
        {
            int errorCode = bank2.deposit(account, amount);
            bank2Error(errorCode);
            break;
        }
        default:
            throw std::invalid_argument("No bank has that account");
            break;
        }
    }
    void deposit(id account, double amount)
    {
        int bank = bankType(account);
        switch (bank)
        {
        case 1:
            bank1.deposit(account, amount);
            break;
        case 2:
            throw std::invalid_argument("Bank 2 doesn't support floating-point deposits");
            break;
        default:
            throw std::invalid_argument("No bank has that account");
            break;
        }
    }
    void withdraw(id account, int amount)
    {
        int bank = bankType(account);
        switch (bank)
        {
        case 1:
            bank1.withdraw(account, amount);
            break;
        case 2:
        {
            int errorCode = bank2.withdraw(account, amount);
            bank2Error(errorCode);
            break;
        }
        default:
            throw std::invalid_argument("No bank has that account");
            break;
        }
    }
    void withdraw(id account, double amount)
    {
        int bank = bankType(account);
        switch (bank)
        {
        case 1:
            bank1.withdraw(account, amount);
            break;
        case 2:
            throw std::invalid_argument("Bank 2 doesn't support floating-point withdrawals");
            break;
        default:
            throw std::invalid_argument("No bank has that account");
            break;
        }
    }

    void create(int bank, id account)
    {
        switch (bank)
        {
        case 1:
            bank1.create(account);
            break;
        case 2:
        {
            int errorCode = bank2.create(account);
            bank2Error(errorCode);
            break;
        }
        default:
            throw std::invalid_argument("Not a supported bank");
            break;
        }
    }
    double get_balance(id account)
    {
        int bank = bankType(account);
        switch (bank)
        {
        case 1:
            return bank1.get_balance(account);
        case 2:
        {
            int result = bank2.deposit(account, 0);
            bank2Error(result);
            return result;
        }
        default:
            throw std::invalid_argument("No bank has that account");
            break;
        }
    }
};

int main()
{

    return 0;
}
