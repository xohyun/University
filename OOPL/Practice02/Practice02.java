//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class Practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("화씨 온도를 입력하세요: ");
		Scanner scan = new Scanner(System.in);
		int f = scan.nextInt();
		double c = ((double)5 / 9) * (f - 32);
		System.out.println("해당하는 섭씨 온도는 " + c + "입니다.");
	}

}
