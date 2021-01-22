//컴퓨터학과 20170988 한소현
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
			System.out.print("예금주 이름을 입력하세요: ");
			String name = scan.next();
			System.out.print("잔고를 입력하세요: ");
			int money = scan.nextInt();
			hm.put(accountNum, new BankAccount(name, money));
		}
			
		int num, work;
		while(true) {
			System.out.println("현재 잔고현황입니다.");
			printAccounts(hm);
			try {
				System.out.print("업데이트할 계좌번호를 입력하세요 (종료-0): ");
				num = scan.nextInt();
				BankAccount b = hm.get(num);
				if (num == 0) {
					System.out.println("프로그램을 종료합니다.");
					break;
				}
				if (b == null) {
					throw new NoSuchAccountException();
				}
				ba = hm.get(num);
				
				System.out.print("원하는 작업을 선택하세요 (1-입금/2-출금): ");
				work = scan.nextInt();	
				if (work < 1 || work > 2) {
					throw new NoSuchOperationException();
				}
				if (work == 1) {
					ba = hm.get(num);
					System.out.print("입금액을 입력하세요: ");
					ba.deposit(scan.nextInt());
					hm.put(num, ba);
					System.out.println("입금이 완료되었습니다.");
				}	
				else {
					ba = hm.get(num);
					System.out.print("출금액을 입력하세요: ");
					ba.withdraw(scan.nextInt());
					hm.put(num, ba);
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
	public static void printAccounts(Map<Integer, BankAccount> m) {
		System.out.println("계좌번호\t계좌주\t잔고");
		for (Map.Entry<Integer, BankAccount> s : m.entrySet()) {
			System.out.println(s.getKey() + "\t" +  s.getValue());
		}
	}
}
