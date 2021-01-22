//컴퓨터학과 20170988 한소현
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
			input1 = "가위";
		}
		else if (n == 1) {
			input1 = "바위";
		}
		else {
			input1 = "보";
		}
		System.out.println("컴퓨터의 생성: " + input1);
		do {
			System.out.print("당신의 입력: ");
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
					System.out.println("당신이 이겼습니다.");
				else {
					System.out.println("컴퓨터가 이겼습니다.");
				}
			}
			
			if (input1.equals("바위")) {
				if (input2.equals("가위")) {
					System.out.println("컴퓨터가 이겼습니다.");
				}
				else {
					System.out.println("당신이 이겼습니다.");
				}
			}
			
			if (input1.equals("보")) {
				if (input2.equals("가위")) {
					System.out.println("당신이 이겼습니다.");
				}
				else {
					System.out.println("컴퓨터가 이겼습니다.");
				}
			}
		}
	}

}
