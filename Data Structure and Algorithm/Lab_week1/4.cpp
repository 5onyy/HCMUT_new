class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        publishingYear = 0;
        title = authors = NULL;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        this->title = new char[strlen(title) + 1];  this->authors = new char[strlen(authors) + 1];
        strcpy(this->title,title);    strcpy(this->authors,authors);    this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        this->title = new char[strlen(book.title) + 1];
        this->authors = new char[strlen(book.authors) + 1];
        strcpy(this->title,book.title);   strcpy(this->authors,book.authors);   this->publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title,title);
    }

    void setAuthors(const char* authors)
    {
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors,authors);
    }

    void setPublishingYear(int publishingYear)
    {
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        return title;
    }

    char* getAuthors() const
    {
        return authors;
    }

    int getPublishingYear() const
    {
        return publishingYear;
    }

    ~Book()
    {
        delete this->title;   delete this->authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};