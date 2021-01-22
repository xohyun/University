//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class PracticeA_04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("정수형 RandomList를 생성합니다.");
		RandomList<Integer> rl = new RandomList<Integer>();
		Scanner scan = new Scanner(System.in);
		int num;
		do {
			System.out.print("\n원하는 기능을 선택하세요(1-추가/2-추가/3-무작위/4-종료) : ");
			num = scan.nextInt();
			if (num == 1) {
				System.out.print("추가하고 싶은 원소의 개수를 입력하세요:");
				int size = scan.nextInt();
				for (int i = 0; i < size; i++) {
					System.out.print("[" + i + "]번 원소 : ");
					int n = scan.nextInt();
					rl.add(n);
				}
			}
			else if (num == 2) {
				rl.print();
			}
			else if (num == 3) {
				try {
					System.out.println("무작위 원소 출력 : " + rl.select());
				}catch(ImproperArraySizeException e) {
					System.out.println("입력된 원소가 없는 상황입니다.");
				}
			}
			else if (num == 4) {
				System.out.println("프로그램을 종료합니다.");
				break;
			}
		}while(num != 4);
	}

}
// 랜덤클래스 절대 사용하면안돼
// 리스트애 았는 내용 복사.copy본을 소속변수에 있는 걸 복사해서 새로운 객체 만드렁서 반환
// 리스트에 있는 걸 하나하나 add해서 새로운 객체 반환해주면돼.
// 예외처리 select에try {