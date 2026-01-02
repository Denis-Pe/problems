(require  ['clojure.string :as 'str])

(let [n-tests (parse-long (read-line))]
  (dotimes [_ n-tests]
    (let [_n-words (parse-long (read-line))
          all-words (read-line)]
      (println (reduce (fn [acc next] 
                         (if (neg? (.compareTo (str next acc) (str acc next)))
                           (str next acc)
                           (str acc next)))
                       ""
                       (str/split all-words #" "))))))


