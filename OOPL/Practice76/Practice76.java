//��ǻ���а� 20170988 �Ѽ���
import java.util.ArrayList;
import java.util.Scanner;

public class Practice76 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		ArrayList<BankAccount> list = new ArrayList<BankAccount>();
		BankAccount ba;
		
		for (int i = 0; i < 3; i++) {
			System.out.print("������ �̸��� �Է��ϼ���: ");
			String name = scan.next();
			System.out.print("�ܰ� �Է��ϼ���: ");
			int money = scan.nextInt();
			ba = new BankAccount(name, money);
			list.add(ba);			
		}
			
		int num, work;
		while(true) {
			show(list);
			try {
				System.out.print("������Ʈ�� ���¹�ȣ�� �Է��ϼ��� (����-0): ");
				num = scan.nextInt();
				if (num < 0 || num > 3) {
					throw new NoSuchAccountException();
				}
				if (num == 0) {
					System.out.println("���α׷��� �����մϴ�.");
					break;
				}
				ba = list.get(num - 1);
				System.out.print("���ϴ� �۾��� �����ϼ��� (1-�Ա�/2-���): ");
				work = scan.nextInt();	
				if (work < 1 || work > 2) {
					throw new NoSuchOperationException();
				}
				if (work == 1) {
					System.out.print("�Աݾ��� �Է��ϼ���: ");
					ba.deposit(scan.nextInt());
					System.out.println("�Ա��� �Ϸ�Ǿ����ϴ�.");
				}	
				else {
					System.out.print("��ݾ��� �Է��ϼ���: ");
					ba.withdraw(scan.nextInt());
					System.out.println("����� �Ϸ�Ǿ����ϴ�.");
				}
			}catch(NoSuchAccountException e) {
				System.out.println("�߸��� ���¹�ȣ�Դϴ�. �ٽ� �Է��ϼ���.");
				continue;
			}catch(NoSuchOperationException e) {
				System.out.println("�߸��� �۾��Դϴ�. �ٽ� �Է��ϼ���.");
				continue;
			}catch(NegativeAmountException e) {
				continue;
			}catch(NegativeBalanceException e) {
				System.out.println("����� �ݾ��� �ܰ��� �����ϴ�. �ٽ� �Է��ϼ���.");
				continue;
			}
		}
	}
	public static void show(ArrayList array) {
		System.out.println("\n���� �ܰ� ��Ȳ�Դϴ�.");
		System.out.println("���¹�ȣ\t������\t�ܰ�");
		for (int i = 0; i < array.size(); i++) {
			System.out.print((i + 1));
			System.out.print(array.get(i));
		}
	}

}
