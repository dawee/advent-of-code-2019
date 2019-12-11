let tap = (handler, value) => {
  handler(value);
  value;
};

let memoize = predicate => {
  let memo = ref(Map.empty());

  input =>
    switch (memo^ |> Map.get(input)) {
    | None =>
      let result = predicate(input);

      memo := memo^ |> Map.set(input, result);
      result;
    | Some(result) => result
    };
};
