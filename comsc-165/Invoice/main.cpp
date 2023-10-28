#include <iostream>
#include <string>

class Invoice {
    public:
        Invoice();
        void setPartNumber(std::string partNumber) { m_partNumber = partNumber; }
        void setPartDescription(std::string partDescription) { m_partDescription = partDescription; }
        void setQuantity(int quantity) { m_quantity = quantity; }
        void setPricePerItem(int pricePerItem) { m_pricePerItem = pricePerItem; }

        std::string getPartNumber() const { return m_partNumber; }
        std::string getPartDescription() const {return m_partDescription; }
        int getQuantity() const { return m_quantity; }
        int getPricePerItem() const { return m_pricePerItem; }
        int getInvoiceAmount() const { return m_quantity * m_pricePerItem; }
        void print() const;

    private:
        std::string m_partNumber;
        std::string m_partDescription;
        int m_quantity;
        int m_pricePerItem;
};

Invoice::Invoice()
{
    m_partNumber = "N/A";
    m_partDescription = "N/A";
    m_quantity = 0;
    m_pricePerItem = 0;
}

void Invoice::print() const
{
    std::cout << "Part number: " << getPartNumber() << '\n';
    std::cout << "Part description: " << getPartDescription() << '\n';
    std::cout << "Quantity: " << getQuantity() << '\n';
    std::cout << "Price per item $" << getPricePerItem() << '\n';
    std::cout << "Invoice amount $" << getInvoiceAmount() << '\n';
}

int main()
{
    std::string partNumber{};
    std::string partDescription{};
    int quantity{};
    int pricePerItem{}; // std::string because user may append '$' in the beginning
    int invoiceAmount{};
    Invoice myInvoice;

    std::cout << "Part number: ";
    getline(std::cin, partNumber);
    myInvoice.setPartNumber(partNumber);

    std::cout << "Part description: ";
    getline(std::cin, partDescription);
    myInvoice.setPartDescription(partDescription);

    std::cout << "Quantity: ";
    std::cin >> quantity;
    if(quantity < 0)
    {
        myInvoice.setQuantity(0);
        std::cout << "Quantity cannot be negative. Set to zero.\n";
    }
    else
    {
        myInvoice.setQuantity(quantity);
    }

    std::cout << "Price per item: ";
    std::cin >> pricePerItem;
    if(pricePerItem < 0)
    {
        myInvoice.setPricePerItem(0);
        std::cout << "Price per item cannot be negative. Set to zero.\n";
    }
    else
    {
        myInvoice.setPricePerItem(pricePerItem);
    }

    std::cout << "\nInvoice data members modified.\n\n";
    myInvoice.print();
    std::cout << "\nEnd of invoice.\n";

    return 0;
}