//컴퓨터학과 20170988 한소현
import java.util.ArrayList;
import java.util.Scanner;

public class Practice76 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		ArrayList<BankAccount> list = new ArrayList<BankAccount>();
		BankAccount ba;
		
		for (int i = 0; i < 3; i++) {
			System.out.print("예금주 이름을 입력하세요: ");
			String name = scan.next();
			System.out.print("잔고를 입력하세요: ");
			int money = scan.nextInt();
			ba = new BankAccount(name, money);
			list.add(ba);			
		}
			
		int num, work;
		while(true) {
			show(list);
			try {
				System.out.print("업데이트할 계좌번호를 입력하세요 (종료-0): ");
				num = scan.nextInt();
				if (num < 0 || num > 3) {
					throw new NoSuchAccountException();
				}
				if (num == 0) {
					System.out.println("프로그램을 종료합니다.");
					break;
				}
				ba = list.get(num - 1);
				System.out.print("원하는 작업을 선택하세요 (1-입금/2-출금): ");
				work = scan.nextInt();	
				if (work < 1 || work > 2) {
					throw new NoSuchOperationException();
				}
				if (work == 1) {
					System.out.print("입금액을 입력하세요: ");
					ba.deposit(scan.nextInt());
					System.out.println("입금이 완료되었습니다.");
				}	
				else {
					System.out.print("출금액을 입력하세요: ");
					ba.withdraw(scan.nextInt());
					System.out.println("출금이 완료되었습니다.");
				}
			}catch(NoSuchAccountException e) {
				System.out.println("잘못된 계좌번호입니다. 다시 입력하세요.");
				continue;
			}catch(NoSuchOperationException e) {
				System.out.println("잘못된 작업입니다. 다시 입력하세요.");
				continue;
			}catch(NegativeAmountException e) {
				continue;
			}catch(NegativeBalanceException e) {
				System.out.println("출금할 금액이 잔고보다 많습니다. 다시 입력하세요.");
				continue;
			}
		}
	}
	public static void show(ArrayList array) {
		System.out.println("\n현재 잔고 현황입니다.");
		System.out.println("계좌번호\t계좌주\t잔고");
		for (int i = 0; i < array.size(); i++) {
			System.out.print((i + 1));
			System.out.print(array.get(i));
		}
	}

}
