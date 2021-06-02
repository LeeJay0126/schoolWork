#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
class DayOfYear
{
    public:
        DayOfYear(int monthValue, int dayValue);
        DayOfYear(int monthValue);
        DayOfYear( );
        void input( );
        void output( );
        int getMonthNumber( );
        int getDay( );
    private:
        int month;
        int day;
        void testDate( );
};

#endif