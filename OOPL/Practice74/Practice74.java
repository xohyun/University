//��ǻ���а� 20170988 �Ѽ���
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Practice74 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("���ϴ� ������ ������ �Է��ϼ���: ");
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();
		System.out.print("�������� ������ �����ϼ���: ");
		int range = scan.nextInt();
		System.out.println("������ ���� �迭�� ������ �����ϴ�.");
		ArrayList<Integer> list1 = getRandomList(size, range);
		printArray10PerLine(list1);
		
		ArrayList<Integer> list2 = sortList(list1);
		System.out.println("���ĵ� ���� �迭�� ������ �����ϴ�.");
		printArray10PerLine(list2);
		System.out.println("������ ���� �迭�� ������ �����ϴ�.");///////�̰žȵ�..�̤�
		printArray10PerLine(list1);
		
		System.out.print("���� ū �� : " + list2.get(0));
		System.out.println(", ���� ���� �� : " + list2.get(list2.size() - 1));
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
// ���û��
// getRandom
//arrayList�� 0���� 100���� �� �־�. �׸��� ����. �׸��� �տ� 10���� ���.
// a �� �״�� ��������.
// ���� �̿��ؼ� ū�� �������� ���ϵ��� ��.
// �Ǿտ��ִ°� ���� ���� ��. 
// getMin getMAx�� �̤�
// max�޼ҵ� ���ȵ�