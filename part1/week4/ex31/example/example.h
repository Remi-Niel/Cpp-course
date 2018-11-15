#ifndef INCLUDED_EXAMPLE_
#define INCLUDED_EXAMPLE_


class example
{
	std::uint8_t *bits;
	std::size_t len;

    public:
        example();
        void show() const;
        void readInput(std::string input);

    private:
    	void setBits(char value, size_t index);
};
        
#endif
