//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.print("��ġ ���� �Է��ϼ���:");
		double inch = scan.nextDouble();
		int centimeter = (int)(2.54 * inch);
		System.out.println("�ش��ϴ� ��Ƽ���� ���� " + centimeter + "�Դϴ�.");
	}

}
