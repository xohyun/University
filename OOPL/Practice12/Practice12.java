//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n;
		do {
			System.out.print("������ �Է��ϼ���: ");
			n = scan.nextInt();
			if (n < 1) {
				System.out.println("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.");
			}
		}while(n < 1);
		
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 5 != 0) {
				count++;
				System.out.print(i + "\t");
			}
			if (count % 7 == 0) {
				System.out.println();
			}
		}
	}

}
//do while ���� Ȯ��.