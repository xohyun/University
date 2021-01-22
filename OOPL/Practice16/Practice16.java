//컴퓨터학과 20170988 한소현
import java.util.Random;
import java.util.Scanner;

public class Practice16 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		boolean error;
		String input1, input2;
		Random rg = new Random();
		int youWin = 0, youLose = 0, youTie = 0;
		
		while(true) {
			System.out.println("현재 당신의 전적: " + youWin + "승 " + youLose + "패 " + youTie + "무");
			error = true;
			int n = rg.nextInt(3);
			if (n == 0) {
				input1 = "가위";
			}
			else if (n == 1) {
				input1 = "바위";
			}
			else {
				input1 = "보";
			}
			System.out.println("컴퓨터의 입력: " + input1);
			do {
				System.out.print("당신의 입력 (가위/바위/보/그만): ");
				input2 = scan.next();
				if (input2.equals("가위")||input2.equals("바위")||input2.equals("보") || input2.equals("그만")) {
					error = false;
				}
				else {
					System.out.println("잘못된 입력입니다. 다시 입력하세요.");
				}
			}while(error);
			
			if (input2.equals("그만")) {
				System.out.println("프로그램을 종료합니다.");
				break;
			}
			
			int win = whoswin(input1, input2);
			if (win == 1) {
				System.out.println("당신이 이겼습니다.");
				youWin++;
			}
			else if (win == 0) {
				System.out.println("비겼습니다.");
				youTie++;
			}
			else {
				System.out.println("컴퓨터가 이겼습니다.");
				youLose++;
			}
		}
	}

	
	public static int whoswin(String com, String you) {
		if (com.equals(you)) {
			return 0;
		}
		
		if (com.equals("가위")) {
			if (you.equals("바위")) {
				return 1;
			}
			else {
				return -1;
			}
		}
		
		else if (com.equals("바위")) {
			if ( you.equals("가위")) {
				return -1;
			}
			else {
				return 1;
			}
		}
		
		else {
			if ( you.equals("가위")) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	
}
