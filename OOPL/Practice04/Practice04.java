//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.print("������ �Է��ϼ���: ");
		int n = scan.nextInt();
		
		if(n % 2 == 0) {
			System.out.println("�Է��� ���� " + n +"�� ¦���Դϴ�.");
		}
		else if(n % 2 == 1) {
			System.out.println("�Է��� ���� " + n +"�� Ȧ���Դϴ�.");
		}
		else {
			System.out.println("�Է��� ���� " + n +"�� �����Դϴ�.");
		}
	}

}
