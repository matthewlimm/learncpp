# if 0
void value; // won't work, variables can't be defined with a void type

// Functions That Do Not Return a Value

void writevalue(int x) // void here means no return value
{
	std::cout << "The value of x is: " << x << '\n';
	// no return statement, because this function doesn't return a value
}

void noReturn(int x) // void here means no return value
{
	return 5; // error
}

// Deprecated: Functions That Do Not Take Parameters

int getValue(void) // void here means no parameters
{
	int x{};
	std::cin >> x;
	return x;
}

int getValue() // empty function parameters is an implicit void
{
	int x{};
	std::cin >> x;
	return x;
}

// best practice: use empty parameter over void parameter for functions without parameters
#endif