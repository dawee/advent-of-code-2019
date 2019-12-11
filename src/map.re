type t('key, 'value);

module Binding = {
  [@bs.module "immutable"] external empty: unit => t('key, 'value) = "Map";
  [@bs.send]
  external set: (t('key, 'value), 'key, 'value) => t('key, 'value) = "set";
  [@bs.send]
  external get: (t('key, 'value), 'key) => Js.Nullable.t('value) = "get";
};

let empty = Binding.empty;
let set = (key, value, map) => Binding.set(map, key, value);
let get = (key, map) => Binding.get(map, key) |> Js.Nullable.toOption;
