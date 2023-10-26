//Bank Account Class Header Template
class BankAccount{
  private:
      const static  double  MIN_BALANCE;
       const static double REWARD_RATE;
       const static double MIN_REWARD_AMOUNT;
 // count of how many bank account objects are created
    public: static int count;
    
    private:
   //account number and account id
      int accountNumber,id;
   // account name
      std::string accountName;
   //account balance
      double accountBalance;

    public: 
  //default contructor
      BankAccount();
  // custom constructor
      BankAccount(std::string accountName, int id,int accountNumber, double accountBalance);
  //getters
      public:
  // display account name
        std::string getAccountName();
 // display account number
        int getAccountNumber();
  //display account balance
        double getAccountBalance();
   // setters : cannot change number and accountName
   //setting balance may be needed by admin

      void setAccountBalance(double accountBalance);
  // display the string representation of the bank account
      std::string toString();
  // withdraw the amount if possible
      bool withdraw(double amount);
  // display the number of existing bank accounts
      int getCount();
  // deposit amount and include rewards if any  
      void deposit(double amount);
   // check if duplicate account exists
      bool equals(BankAccount other);
   // private helper functions to add reward and 
      private: void addReward(double amount);
   // get account ID
      private: int getId();

    
};
 