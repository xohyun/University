//컴퓨터학과 20170988 한소현
import java.util.Random;

public class Practice08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random rg = new Random();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				System.out.print(rg.nextInt(100) + "\t");
			}
			System.out.println();
		}
	}

}
