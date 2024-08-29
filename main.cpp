
class Node {

public:

    int m_data;
    Node* m_link;

    Node(int data, Node* link=nullptr)
        : m_data {data}
        , m_link {link} {}

};

class LinkedList {

private:

    Node* m_head;

public:

    LinkedList()
        : m_head {nullptr} {}


    void insertNode(int value) {

        Node* newNode = new Node(value);

        if (m_head == nullptr) {
            m_head = newNode;
        } else {
            Node* temp = m_head;
            while (temp->m_link != nullptr) {
                temp = temp->m_link;
            }
            temp->m_link = newNode;
        }
    }

    void printList() const {

        Node* m_current = m_head;

        if (m_current == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        while (m_current != nullptr) {

            cout << m_current->m_data << ' ';
            m_current = m_current->m_link;

        }
        cout << '\n';
    }

    void deleteNode(int value) {

        if (m_head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (m_head->m_data == value) {
            Node* m_oldNode = m_head;
            m_head = m_head->m_link;
            delete m_oldNode;
            return;
        }

        Node* current = m_head->m_link;
        Node* previous = m_head;

        while (current != nullptr) {
            if (current->m_data == value) {
                previous->m_link = current->m_link;
                delete current;
                return;
            }
            previous = current;
            current = current->m_link;
        }
    }

    bool searchNode(int value) const {

        if (m_head == nullptr) {
            cout << "List is empty.\n";
            return false;
        }

        if (m_head->m_data == value) {
            return true;
        }

        Node* current = m_head->m_link;

        while (current != nullptr) {
            if (current->m_data == value) {
                return true;
            }
            current = current->m_link;
        }
        return false;
    }

};

int main() {

    LinkedList list;

    int num = 0;

    while (num < 10) {
        list.insertNode(num);
        ++num;
    }
    list.printList();

    if (list.searchNode(5)) {
        list.deleteNode(5);
    }
    list.printList();

    if (list.searchNode(9)) {
        list.insertNode(10);
    }
    list.printList();

}
