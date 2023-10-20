string timeInWords(int h, int m)
{
    string output = "";
    bool isOver30 = false;
    int mins[2] = { 0, 0 };
    string hour[14] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen" };

    if (m > 30)
    {
        isOver30 = true;
        m = 60 - m;
    }

    mins[0] = m / 10;
    mins[1] = m % 10;

    switch (m)
    {
    case 0:
        output = hour[h] + " o' clock";
        return output;
    case 1:
        output = "one minute";
        if (isOver30)
            output += " to " + hour[h + 1];
        else
            output += " past " + hour[h];
        return output;
    case 10:
        output = "ten minutes";
        break;
    case 11:
        output = "eleven minutes";
        break;
    case 12:
        output = "twelve minutes";
        break;
    case 13:
        output = "thirteen minutes";
        break;
    case 15:
        output = "quarter";
        break;
    case 30:
        output = "half past " + hour[h];
        return output;
    default:
        if (mins[0] == 1)
        {
            output = hour[mins[1]] + "teen";
        }
        else if (mins[0] == 2)
        {
            output = "twenty " + hour[mins[1]];
        }
        else
        {
            output = hour[mins[1]];
        }

        output += " minutes";

        break;
    }

    if (isOver30)
        output += " to " + hour[h + 1];
    else
        output += " past " + hour[h];

    return output;
}