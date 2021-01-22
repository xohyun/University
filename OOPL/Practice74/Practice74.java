//컴퓨터학과 20170988 한소현
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Practice74 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("원하는 난수의 개수를 입력하세요: ");
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();
		System.out.print("난수값의 범위를 설정하세요: ");
		int range = scan.nextInt();
		System.out.println("생성된 난수 배열은 다음과 같습니다.");
		ArrayList<Integer> list1 = getRandomList(size, range);
		printArray10PerLine(list1);
		
		ArrayList<Integer> list2 = sortList(list1);
		System.out.println("정렬된 난수 배열은 다음과 같습니다.");
		printArray10PerLine(list2);
		System.out.println("원래의 난수 배열은 다음과 같습니다.");///////이거안돼..ㅜㅜ
		printArray10PerLine(list1);
		
		System.out.print("가장 큰 값 : " + list2.get(0));
		System.out.println(", 가장 작은 값 : " + list2.get(list2.size() - 1));
	}
	
	public static void printArray10PerLine(ArrayList<Integer> a) {
		for (int i = 0; i < a.size(); i++) {
			System.out.print(a.get(i) + "\t");
			if ((i + 1) % 10 == 0) {
				System.out.println();
			}
		}
		System.out.println();
	}
	public static ArrayList<Integer> getRandomList(int size, int range) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i <= range; i++) {
			list.add(i);
		}
		Collections.shuffle(list);
		ArrayList<Integer> nList = new ArrayList<Integer>();
		for (int i = 0; i < size; i++) {
			nList.add(list.get(i));
		}
		return nList;
	}
	public static ArrayList<Integer> sortList(ArrayList<Integer> a) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i <  a.size(); i++) {
			list.add(a.get(i));
		}
		Collections.sort(list);
		return list;
	}
}
// 셔플사용
// getRandom
//arrayList에 0부터 100개를 다 넣어. 그리고 셔플. 그리고 앞에 10개만 출력.
// a 는 그대로 보내야함.
// 정렬 이용해서 큰값 작은값을 구하도록 함.
// 맨앞에있는게 가장 작은 값. 
// getMin getMAx도 ㅜㅜ
// max메소드 도안돼