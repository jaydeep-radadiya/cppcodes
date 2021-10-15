public class ReorderLinkedlist {
    // find the middle of ll
    // breack it down into two ll from middle
    // reverse the second half of ll
    // merge both of the two ll by reordering

    private class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node reverse(Node head) {
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

    void reorder(Node first, Node second) {
        while (second.next != null) {
            Node temp = first.next;
            first.next = second;
            first = temp;
            temp = second.next;
            second.next = first;
            second = temp;
        }
    }

    Node reorderlist(Node head) {
        Node slow = head;
        Node fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        Node first = head;
        Node second = reverse(slow);
        reorder(first, second);
        return head;
    }
}