//��ǻ���а� 20170988 �Ѽ���
import java.util.Random;
import java.util.Scanner;

public class Practice15 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		boolean error = true;
		String input1, input2;
		Random rg = new Random();
		
		int n = rg.nextInt(3);
		if (n == 0) {
			input1 = "����";
		}
		else if (n == 1) {
			input1 = "����";
		}
		else {
			input1 = "��";
		}
		System.out.println("��ǻ���� ����: " + input1);
		do {
			System.out.print("����� �Է�: ");
			input2 = scan.next();
			if (input2.equals("����")||input2.equals("����")||input2.equals("��")) {
				error = false;
			}

			else {
				System.out.println("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.");
			}
		}while(error);
		
		int win = whoswin(input1, input2);
		if (win == 1) {
			System.out.println("����� �̰���ϴ�.");
		}
		else if (win == 0) {
			System.out.println("�����ϴ�.");
		}
		else {
			System.out.println("��ǻ�Ͱ� �̰���ϴ�.");
		}
	}
	
	public static int whoswin(String com, String you) {
		if (com.equals(you)) {
			return 0;
		}
		
		if (com.equals("����")) {
			if (you.equals("����")) {
				return 1;
			}
			else {
				return -1;
			}
		}
		
		else if (com.equals("����")) {
			if ( you.equals("����")) {
				return -1;
			}
			else {
				return 1;
			}
		}
		
		else {
			if ( you.equals("����")) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}
}
