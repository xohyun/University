//��ǻ���а� 20170988 �Ѽ���
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;

public class Practice77 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Map<Integer, BankAccount> hm = new HashMap<Integer, BankAccount>();
		Scanner scan = new Scanner(System.in);
		BankAccount ba;
		
		for (int i = 0; i < 3; i++) {
			Random rg = new Random();
			int accountNum = rg.nextInt(9000) + 1000;
			System.out.print("������ �̸��� �Է��ϼ���: ");
			String name = scan.next();
			System.out.print("�ܰ� �Է��ϼ���: ");
			int money = scan.nextInt();
			hm.put(accountNum, new BankAccount(name, money));
		}
			
		int num, work;
		while(true) {
			System.out.println("���� �ܰ���Ȳ�Դϴ�.");
			printAccounts(hm);
			try {
				System.out.print("������Ʈ�� ���¹�ȣ�� �Է��ϼ��� (����-0): ");
				num = scan.nextInt();
				BankAccount b = hm.get(num);
				if (num == 0) {
					System.out.println("���α׷��� �����մϴ�.");
					break;
				}
				if (b == null) {
					throw new NoSuchAccountException();
				}
				ba = hm.get(num);
				
				System.out.print("���ϴ� �۾��� �����ϼ��� (1-�Ա�/2-���): ");
				work = scan.nextInt();	
				if (work < 1 || work > 2) {
					throw new NoSuchOperationException();
				}
				if (work == 1) {
					ba = hm.get(num);
					System.out.print("�Աݾ��� �Է��ϼ���: ");
					ba.deposit(scan.nextInt());
					hm.put(num, ba);
					System.out.println("�Ա��� �Ϸ�Ǿ����ϴ�.");
				}	
				else {
					ba = hm.get(num);
					System.out.print("��ݾ��� �Է��ϼ���: ");
					ba.withdraw(scan.nextInt());
					hm.put(num, ba);
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
	public static void printAccounts(Map<Integer, BankAccount> m) {
		System.out.println("���¹�ȣ\t������\t�ܰ�");
		for (Map.Entry<Integer, BankAccount> s : m.entrySet()) {
			System.out.println(s.getKey() + "\t" +  s.getValue());
		}
	}
}
