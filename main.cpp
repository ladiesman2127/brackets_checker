#include <iostream>
#include <stack>
int main() {
  std::stack<std::pair<char, int>> open_brackets;
	int curr_pos = 0;
	for (auto ch : s)
	{
		++curr_pos;
		if (ch == '(' || ch == '[' || ch == '{')
		{
			open_brackets.emplace(ch, curr_pos);
		}
		else if (ch == ')' || ch == ']' || ch == '}')
		{
			if (open_brackets.empty())
			{
				std::cout << curr_pos;
				return;
			}
			const int top = open_brackets.top().first;
			open_brackets.pop();
			if (ch == ')' && top != '(' || ch == ']' && top != '[' || ch == '}' && top != '{')
			{
				std::cout << std::to_string(curr_pos);
				return;
			}
		}
	}
	if (open_brackets.empty())
	{
		std::cout << "Success";
	}
	else
	{
		std::cout << open_brackets.top().second;
	}
    return 0;
}
