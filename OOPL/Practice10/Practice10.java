//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int n, total = 0, numberCount = 0;
		do {
			System.out.print("���ڸ� �Է��ϼ���: ");
			n = scan.nextInt();
			if (n < 0) {
				System.out.println("������ �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���.");
				continue;
			}
			else if (n > 0) {
				total += n;
				numberCount++;
			}
		}while (n != 0);
		System.out.println("�Էµ� ���ڵ��� ���� " + total + "�Դϴ�.");
		System.out.println("�Էµ� ���ڵ� �߿��� 0���� ū ������ ������ " + numberCount + "�Դϴ�.");
		System.out.println("�Էµ� ���ڵ��� ����� " + (double)total/numberCount + "�Դϴ�.");
	}

}
