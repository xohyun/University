//컴퓨터학과 20170988 한소현
public class BankAccount {
	private String owner;
	private int balance;
	
	public BankAccount() {
		this("모름", -1);
	}
	public BankAccount(String owner, int balance) {
		this.owner = owner;
		this.balance = balance;
	}
	
	public void setOwner(String owner) {
		this.owner = owner;
	}
	public String getOwner() {
		return owner;
	}
	public void setBalance(int balance) {
		this.balance = balance;
	}
	public int getBalance() {
		return balance;
	}
	
	public String toString() {
		String rslt = "";
		
		rslt += "\t" + owner;
		rslt += "\t" + balance + "\n";
		
		return rslt;
	}
	public void deposit(int money) throws NegativeAmountException{ //예금
		if (money < 0) {
			throw new NegativeAmountException(1);
		}
		balance += money;
	}
	public void withdraw(int money) throws NegativeBalanceException, NegativeAmountException{ //인출
		if (money < 0) {
			throw new NegativeAmountException(2);
		}
		if (balance < money) {
			throw new NegativeBalanceException();
		}
		balance -= money;
	}
}
