⍝ code_report Solution
⍝ Problem Link: https://www.hackerrank.com/contests/hack-the-interview-global/challenges/heads-or-tails/problem

⍝ One liner
getMaxStreaks ← {{⌈/+/¨(1,2≠/⍵)⊂⍵}(⍤1)⍉y,(⍤0)~y←'Heads'∘≡¨⍵}

⍝ More liner
headsTails ← {⍉y,(⍤0)~y←'Heads'∘≡¨⍵}
chunkEqual ← {(1,2≠/⍵)⊂⍵}
getMaxStreaks ← {{⌈/+/¨chunkEqual}(⍤1)headsTails ⍵}
