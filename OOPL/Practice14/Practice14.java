//��ǻ���а� 20170988 �Ѽ���
import java.util.Random;
import java.util.Scanner;

public class Practice14 {

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
		
		if (input1.equals(input2)) {
			System.out.println("�����ϴ�.");
		}
		
		else {
			if (input1.equals("����")) {
				if (input2.equals("����")) 
					System.out.println("����� �̰���ϴ�.");
				else {
					System.out.println("��ǻ�Ͱ� �̰���ϴ�.");
				}
			}
			
			if (input1.equals("����")) {
				if (input2.equals("����")) {
					System.out.println("��ǻ�Ͱ� �̰���ϴ�.");
				}
				else {
					System.out.println("����� �̰���ϴ�.");
				}
			}
			
			if (input1.equals("��")) {
				if (input2.equals("����")) {
					System.out.println("����� �̰���ϴ�.");
				}
				else {
					System.out.println("��ǻ�Ͱ� �̰���ϴ�.");
				}
			}
		}
	}

}
