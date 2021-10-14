public class LinkedlistByRiya {
    private class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;

    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public void addFirst(int data) {
        Node temp = new Node(data);
        temp.next = head;
        head = temp;
    }

    public void addLast(int data) {
        Node node = new Node(data);
        if (head == null) {
            head = node;
            return;
        }

        Node temp = head;
        while (temp.next != null)
            temp = temp.next;
        temp.next = node;
    }

    public void addMiddle(int idx, int data) {
        if (idx < 0) {
            return;
        }
        if (idx == 0) {
            addFirst(data);
            return;
        }

        int cnt = 0;
        Node temp = head;
        Node node = new Node(data);
        while (cnt < idx - 1) {
            temp = temp.next;
            cnt++;
        }
        node.next = temp.next;
        temp.next = node;
    }
}