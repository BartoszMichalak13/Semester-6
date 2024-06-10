;; 1. Binomial
(defun binomial (n k)
  (cond
    ((or (= k 0) (= k n)) 1)
    (t
      (+ (binomial (- n 1) k)
        (binomial (- n 1) (- k 1))
      )
    )
  )
)

;; 2. Binomial2
(defun binomial2 (n k)
  (nth k (pascal-row n))
)

(defun pascal-row (n)
  (if (= n 0)
    '(1)
    (let ((previous-row (pascal-row (- n 1))))
      (cons 1
        (append (mapcar #'+ (butlast previous-row) (rest previous-row))
                '(1))
      )
    )
  )
)

;; 3. Mergesort
(defun myMerge (list1 list2)
  "Merge two sorted lists into one sorted list."
  (cond
    ((null list1) list2)
    ((null list2) list1)
    (
      (< (car list1) (car list2))
      (cons (car list1) (myMerge (cdr list1) list2))
    )
    (t 
      (cons (car list2)
      (myMerge list1 (cdr list2)))
    )
  )
)

(defun mergesort (list)
  "Sort a list using the Merge Sort algorithm."
  (let* ((len (length list))
         (mid (if (evenp len)
                  (/ len 2)
                  (floor (- len 1) 2)))
         (left (subseq list 0 mid))
         (right (subseq list mid)))
    (if (< len 2)
        list
        (myMerge (mergesort left) (mergesort right))
    )
  )
)

;; 4. De
(defun egcd (a b)
  (if (= b 0)
    (list a 1 0)
    (let* ( (q (floor a b))
            (r (mod a b))
            (result (egcd b r))
          )
          ( list (car result)
            (caddr result)
            (- (cadr result) (* q (caddr result)))
          )
    )
  )
)

(defun de (a b)
  (let ((result (egcd a b)))
    (list (cadr result) (caddr result) (car result))
  )
)

;; 5. PrimeFactors
(defun primeFactors (n)
  (labels ((factor (n divisor)
             (cond
               ((= n 1) '())
               (  (= (mod n divisor) 0)
                  (cons divisor (factor (/ n divisor) divisor)))
               (t (factor n (+ divisor 1)))
              )
            ))
    (factor n 2)
  )
)

;; 6. Totient
(defun myGcd (a b)
  (if (= b 0)
    a
    (myGcd b (mod a b))
  )
)

(defun totient (n)
  (let ((count 0))
    (dotimes (i n count)
      (if (= (myGcd (1+ i) n) 1)
          (incf count)
      )
    )
  )
)

(defun totient3 (n)
  (let ((count 0))
    (labels 
      ((helper (i)
        (if(>= i n)
          count
          (if (= (myGcd (1+ i) n) 1)
            (progn  (incf count)
                    (helper (1+ i)))
            (helper (1+ i))
          )
        )
      ))
      (helper 0)
    )
  )
)

;; 7. Totient2
(defun unique (list)
  (if (null list)
    '()
    (cons (car list)
          (unique (remove (car list) (cdr list)))
    )
  )
)

(defun totient2 (n)
  (let ((factors (unique (primeFactors n))))
    (reduce #'* (mapcar (lambda (p) (- 1 (/ 1 p))) factors)
                :initial-value n)
  )
)

;; 8. Primes
(defun generate-range (start end)
  (if (> start end)
    nil
    (cons start (generate-range (1+ start) end))
  )
)

(defun primes (n)
  (sieve (generate-range 2 n))
)

(defun sieve (lst)
  (if (null lst)
    nil
    (let  ( (p (car lst))
            (xs (cdr lst)))
          (cons p (sieve (remove-if #'(lambda (x) (zerop (mod x p))) xs)))
    )
  )
)

