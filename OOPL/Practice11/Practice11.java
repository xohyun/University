//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in); 

		int n;
		
		do {
			System.out.print("���ڸ� �Է��ϼ���: ");
			n = scan.nextInt();
			if (n < 1) {
				System.out.println("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.");
			}
		}while(n < 1);
		
		boolean isPrime = true;
		
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		
		if (isPrime == false || n == 1) {
			System.out.println("�Էµ� ���� " + n +"�� �Ҽ��� �ƴմϴ�.");
		}
		else {
			System.out.println("�Էµ� ���� " + n +"�� �Ҽ��Դϴ�.");
		}
	}

}
