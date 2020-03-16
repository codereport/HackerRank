-- code_report Solution
-- Problem Link: https://www.hackerrank.com/contests/hack-the-interview-global/challenges/heads-or-tails/problem

maximumOr0 [] = 0
maximumOr0 xs = maximum xs

streak toss = maximumOr0
            . map length 
            . filter ((toss==) . head)
            . group

getMaxStreaks tosses = [(streak "Heads" tosses), 
                        (streak "Tails" tosses)]
