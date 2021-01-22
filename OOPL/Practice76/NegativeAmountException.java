//컴퓨터학과 20170988 한소현
public class NegativeAmountException extends Exception{
	public NegativeAmountException (int num) {
		if (num == 1) {
			System.out.println("입금액이 음수입니다.");
		}
		else if (num == 2) {
			System.out.println("출금액이 음수입니다.");
		}
	}
	
}
