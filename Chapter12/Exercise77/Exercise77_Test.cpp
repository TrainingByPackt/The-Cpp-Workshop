//Chapter 12 : Exercise 77

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Question
{
public:

	Question(int questionNumber, string question, int answerIndex) : m_questionNumber(questionNumber), m_question(question), m_answerIndex(answerIndex) {}

	int getQuestionNumber() const { return m_questionNumber; }
	string getQuestion() const { return m_question; }
	int getAnswerIndex() const { return m_answerIndex; }

private:

	int m_questionNumber;
	string m_question;
	int m_answerIndex;
};
struct QuestionCompare
{
	bool operator() (const Question& lhs, const Question& rhs) const
	{
		return lhs.getQuestionNumber() < rhs.getQuestionNumber();
	}
};

std::string TestCase(int answer) {
	map<Question, vector<string>, QuestionCompare> quiz;
	Question question1(1, "Which two actors directed themselves in movies and won Oscars for Best Actor?", 2);
	vector<string> question1Answers =
	{
	   "Al Pacino and Timothy Hutton",
	   "Jack Nicholson and Kevin Spacey",
	   "Laurence Olivier and Roberto Benigni",
	   "Tom Hanks and Paul Newman"
	};
	Question question2(2, "\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?", 0);
	vector<string> question2Answers =
	{
	   "Gone With the Wind",
	   "Great Expectations",
	   "Harold and Maude",
	   "The Matrix"
	};

	quiz.insert(make_pair(question1, question1Answers));
	quiz.insert(make_pair(question2, question2Answers));
	out << "Welcome to the movie quiz" << endl;
	out << "Type your answer between 1-4 and press enter:" << endl;

	map<Question, vector<string>>::iterator quizIterator = quiz.begin();

	vector<bool> correctAnswers;

	while (quizIterator != quiz.end())
	{
		out << quizIterator->first.getQuestion() << endl;

		int answerIndex = 1;
		for (auto answer : quizIterator->second)
		{
			out << answerIndex << " : " << answer << endl;
			answerIndex++;
		}

		int correctAnswer = quizIterator->first.getAnswerIndex();
		bool wasCorrect = answer - 1 == correctAnswer;

		out << (wasCorrect ? "CORRECT!" : "INCORRECT!") << " Correct answer is: " << quizIterator->second[correctAnswer] << endl;

		if (wasCorrect)
			correctAnswers.push_back(answer);

		quizIterator++;
	}

	out << "Your score was " << correctAnswers.size() << " out of " << quiz.size() << endl;
	out << "done";

	return out.str();
}

TEST(Chapter12, Exercise77) {

	EXPECT_EQ("Welcome to the movie quiz\nType your answer between 1-4 and press enter:\nWhich two actors directed themselves in movies and won Oscars for Best Actor?\n1 : Al Pacino and Timothy Hutton\n2 : Jack Nicholson and Kevin Spacey\n3 : Laurence Olivier and Roberto Benigni\n4 : Tom Hanks and Paul Newman\nINCORRECT! Correct answer is: Laurence Olivier and Roberto Benigni\n\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?\n1 : Gone With the Wind\n2 : Great Expectations\n3 : Harold and Maude\n4 : The Matrix\nINCORRECT! Correct answer is: Gone With the Wind\nYour score was 0 out of 2\ndone", TestCase(2));
	EXPECT_EQ("Welcome to the movie quiz\nType your answer between 1-4 and press enter:\nWhich two actors directed themselves in movies and won Oscars for Best Actor?\n1 : Al Pacino and Timothy Hutton\n2 : Jack Nicholson and Kevin Spacey\n3 : Laurence Olivier and Roberto Benigni\n4 : Tom Hanks and Paul Newman\nINCORRECT! Correct answer is: Laurence Olivier and Roberto Benigni\n\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?\n1 : Gone With the Wind\n2 : Great Expectations\n3 : Harold and Maude\n4 : The Matrix\nINCORRECT! Correct answer is: Gone With the Wind\nYour score was 0 out of 2\ndoneWelcome to the movie quiz\nType your answer between 1-4 and press enter:\nWhich two actors directed themselves in movies and won Oscars for Best Actor?\n1 : Al Pacino and Timothy Hutton\n2 : Jack Nicholson and Kevin Spacey\n3 : Laurence Olivier and Roberto Benigni\n4 : Tom Hanks and Paul Newman\nCORRECT! Correct answer is: Laurence Olivier and Roberto Benigni\n\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?\n1 : Gone With the Wind\n2 : Great Expectations\n3 : Harold and Maude\n4 : The Matrix\nINCORRECT! Correct answer is: Gone With the Wind\nYour score was 1 out of 2\ndone", TestCase(3));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}