//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class Practice13 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		boolean error = true;
		String input1, input2;
		do {
			System.out.print("철수의 입력: ");
			input1 = scan.next();
			if (input1.equals("가위")||input1.equals("바위")||input1.equals("보")) {
				error = false;
			}
			else {
				System.out.println("잘못된 입력입니다. 다시 입력하세요.");
			}
		}while(error);
		
		error = true;
		do {
			System.out.print("영희의 입력: ");
			input2 = scan.next();
			if (input2.equals("가위")||input2.equals("바위")||input2.equals("보")) {
				error = false;
			}

			else {
				System.out.println("잘못된 입력입니다. 다시 입력하세요.");
			}
		}while(error);
		
		if (input1.equals(input2)) {
			System.out.println("비겼습니다.");
		}
		
		else {
			if (input1.equals("가위")) {
				if (input2.equals("바위")) 
					System.out.println("영희가 이겼습니다.");
				else {
					System.out.println("철수가 이겼습니다.");
				}
			}
			
			if (input1.equals("바위")) {
				if (input2.equals("가위")) {
					System.out.println("철수가 이겼습니다.");
				}
				else {
					System.out.println("영희가 이겼습니다.");
				}
			}
			
			if (input1.equals("보")) {
				if (input2.equals("가위")) {
					System.out.println("영희가 이겼습니다.");
				}
				else {
					System.out.println("철수가 이겼습니다.");
				}
			}
		}
	}

}