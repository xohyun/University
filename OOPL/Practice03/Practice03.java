//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class Practice03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.print("인치 값을 입력하세요:");
		double inch = scan.nextDouble();
		int centimeter = (int)(2.54 * inch);
		System.out.println("해당하는 센티미터 값은 " + centimeter + "입니다.");
	}

}
