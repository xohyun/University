//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class PracticeA_04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("������ RandomList�� �����մϴ�.");
		RandomList<Integer> rl = new RandomList<Integer>();
		Scanner scan = new Scanner(System.in);
		int num;
		do {
			System.out.print("\n���ϴ� ����� �����ϼ���(1-�߰�/2-�߰�/3-������/4-����) : ");
			num = scan.nextInt();
			if (num == 1) {
				System.out.print("�߰��ϰ� ���� ������ ������ �Է��ϼ���:");
				int size = scan.nextInt();
				for (int i = 0; i < size; i++) {
					System.out.print("[" + i + "]�� ���� : ");
					int n = scan.nextInt();
					rl.add(n);
				}
			}
			else if (num == 2) {
				rl.print();
			}
			else if (num == 3) {
				try {
					System.out.println("������ ���� ��� : " + rl.select());
				}catch(ImproperArraySizeException e) {
					System.out.println("�Էµ� ���Ұ� ���� ��Ȳ�Դϴ�.");
				}
			}
			else if (num == 4) {
				System.out.println("���α׷��� �����մϴ�.");
				break;
			}
		}while(num != 4);
	}

}
// ����Ŭ���� ���� ����ϸ�ȵ�
// ����Ʈ�� �Ҵ� ���� ����.copy���� �ҼӺ����� �ִ� �� �����ؼ� ���ο� ��ü ���巷�� ��ȯ
// ����Ʈ�� �ִ� �� �ϳ��ϳ� add�ؼ� ���ο� ��ü ��ȯ���ָ��.
// ����ó�� select��try {