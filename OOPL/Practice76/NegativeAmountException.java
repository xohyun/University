//��ǻ���а� 20170988 �Ѽ���
public class NegativeAmountException extends Exception{
	public NegativeAmountException (int num) {
		if (num == 1) {
			System.out.println("�Աݾ��� �����Դϴ�.");
		}
		else if (num == 2) {
			System.out.println("��ݾ��� �����Դϴ�.");
		}
	}
	
}
