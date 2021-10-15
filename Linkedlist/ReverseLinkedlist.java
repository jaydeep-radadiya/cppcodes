public class ReverseLinkedlist {
    private class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node reverseList(Node head) {
        if (head == null || head.next == null)
            return head;

        Node p1 = head;
        Node p2 = p1.next;
        Node p3 = p2.next;
        p1.next = null;
        p2.next = p1;

        while (p3 != null) {
            p1 = p2;
            p2 = p3;
            p3 = p3.next;
            p2.next = p1;
        }
        head = p2;
        return head;
    }
}