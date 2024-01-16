// ---------- Getters ----------

static int getNbAccounts(void);
{
  return(this->_nbAccounts);
}

static int  getTotalAmount(void);
{
  return(this->_totalAmount);
}

static int getNbDeposits(void)
{
  return(this->_totalNbDeposits);
}

static int getNbWithdrawals(void)
{
  return(this->_totalNbWithdrawals);
}

// ---------- Utils ----------

static void displayAccountsInfos(void)
{
  this->_displayTimestanp();
  std::out << "accounts:" << this->getNbAccounts() << ";";
  std::out << "total:" << this->getTotalAmount << ";";
  std::out << "deposits:" << this->getNbDeposits << ";";
  std::out << "withdrawals:" << this->getNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
  this->_accountIndex = this->_nbAccounts;
  this->_amount = this->initial_deposit;
  
}
