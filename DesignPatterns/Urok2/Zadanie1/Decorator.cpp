#include <iostream>
#include <string>
#include <Windows.h>


class Text {
public:
	virtual void render(const std::string& data) const {
		std::cout << data;
	}
};

class DecoratedText : public Text {
public:
	explicit DecoratedText(Text* text) : text_(text) {}
	~DecoratedText()
	{
		//delete text_; // не знаю как правильно освободить память после "new"
	}
	Text* text_ = nullptr;
};

class ItalicText : public DecoratedText {
public:
	explicit ItalicText(Text* text) : DecoratedText(text) {}
	void render(const std::string& data)  const {
		std::cout << "<i>";
		text_->render(data);
		std::cout << "</i>";
	}
};

class BoldText : public DecoratedText {
public:
	explicit BoldText(Text* text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::cout << "<b>";
		text_->render(data);
		std::cout << "</b>";
	}
};

class Paragraph : public DecoratedText {
public:
	explicit Paragraph(Text* text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::cout << "<p>";
		text_->render(data);
		std::cout << "</p>";
	}
};

class Reversed : public DecoratedText {
public:
	explicit Reversed(Text* text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::string _data_{ data };
		std::reverse(_data_.begin(), _data_.end());
		text_->render(_data_);
	}
};

class Link : public DecoratedText {
public:
	explicit Link(Text* text) : DecoratedText(text) {}
	void render(const std::string& data, const std::string& data1) const {
		std::cout << "<a href=";
		text_->render(data);
		std::cout << ">";

		text_->render(data1);
		std::cout << "</a>";
	}
};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	auto text_block = new ItalicText(new BoldText(new Text()));
	text_block->render("Hello world");
	std::cout << std::endl;

	auto text_block1{ new Paragraph(new Text()) };
	text_block1->render("Hello world");
	std::cout << std::endl;

	auto text_block2 = new Reversed(new Text());
	text_block2->render("Hello world");
	std::cout << std::endl;

	auto text_block3 = new Link(new Text());
	text_block3->render("netology.ru", "Hello world");
	std::cout << std::endl;

	//delete text_block; // не знаю как правильно освободить память после "new"
	return 0;
}