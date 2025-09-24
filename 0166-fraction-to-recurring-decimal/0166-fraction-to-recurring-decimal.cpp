class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        std::string fraction;
        if ((numerator < 0) ^ (denominator < 0)) {
            fraction += "-";
        }

        long long dividend = std::llabs((long long)numerator);
        long long divisor = std::llabs((long long)denominator);
        fraction += std::to_string(dividend / divisor);
        long long remainder = dividend % divisor;
        if (remainder == 0) {
            return fraction;
        }

        fraction += ".";
        std::unordered_map<long long, int> map;
        while (remainder != 0) {
            if (map.count(remainder)) {
                fraction.insert(map[remainder], "(");
                fraction += ")";
                break;
            }
            map[remainder] = fraction.size();
            remainder *= 10;
            fraction += std::to_string(remainder / divisor);
            remainder %= divisor;
        }

        return fraction;
    }
};