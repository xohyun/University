//��ǻ���а� 20170988 �Ѽ���
import java.util.Scanner;

public class Practice13 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		boolean error = true;
		String input1, input2;
		do {
			System.out.print("ö���� �Է�: ");
			input1 = scan.next();
			if (input1.equals("����")||input1.equals("����")||input1.equals("��")) {
				error = false;
			}
			else {
				System.out.println("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.");
			}
		}while(error);
		
		error = true;
		do {
			System.out.print("������ �Է�: ");
			input2 = scan.next();
			if (input2.equals("����")||input2.equals("����")||input2.equals("��")) {
				error = false;
			}

			else {
				System.out.println("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.");
			}
		}while(error);
		
		if (input1.equals(input2)) {
			System.out.println("�����ϴ�.");
		}
		
		else {
			if (input1.equals("����")) {
				if (input2.equals("����")) 
					System.out.println("���� �̰���ϴ�.");
				else {
					System.out.println("ö���� �̰���ϴ�.");
				}
			}
			
			if (input1.equals("����")) {
				if (input2.equals("����")) {
					System.out.println("ö���� �̰���ϴ�.");
				}
				else {
					System.out.println("���� �̰���ϴ�.");
				}
			}
			
			if (input1.equals("��")) {
				if (input2.equals("����")) {
					System.out.println("���� �̰���ϴ�.");
				}
				else {
					System.out.println("ö���� �̰���ϴ�.");
				}
			}
		}
	}

}