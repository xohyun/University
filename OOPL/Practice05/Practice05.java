//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.print("������ �Է��ϼ���: ");
		int n = scan.nextInt();
		
		if (n >= 0) {
			System.out.println("�Է��� ���� " + n + "�� ���밪�� " + n + "�Դϴ�.");
		}
		else {
			System.out.println("�Է��� ���� " + n + "�� ���밪�� " + (-n) + "�Դϴ�.");
		}
	}

}
