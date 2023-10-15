
class BankAccount{
  private:
      const static  double  MIN_BALANCE;
       const static double REWARD_RATE;
       const static double MIN_REWARD_AMOUNT;
    private:
      int accountNumber,id;
      std::string accountName;
      double accountBalance;

    public: 
      BankAccount(){};
      BankAccount(std::string accountName, int id,int accountNumber, double accountBalance);
       //getters
      public:
        std::string getAccountName();
        int getAccountNumber();
        double getAccountBalance();
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void setAccountBalance(double accountBalance);

      std::string toString();

      bool withdraw(double amount);
      
      void deposit(double amount);
      bool equals(BankAccount other);
      private: void addReward(double amount);
      private: int getId();

    
};
 