//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice09 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int n, total = 0;
		do {
			System.out.print("���ڸ� �Է��ϼ���: ");
			n = scan.nextInt();
			if (n < 0) {
				System.out.println("������ �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���.");
				continue;
			}
			total += n;
		}while (n != 0);
		System.out.println("�Էµ� ���ڵ��� ���� " + total + "�Դϴ�.");
	}

}
