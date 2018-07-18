/* This is the basic component. */
let component = ReasonReact.statelessComponent("Page");

let handleClick = _event => Js.log("clicked!");

type access =
  | Admin
  | User
  | Worker;

type person = {
  username: string,
  permission: access,
};

let data: array(person) = [|
  {username: "Matt", permission: Admin},
  {username: "Luke", permission: Worker},
  {username: "Jacob", permission: Worker},
  {username: "Mike", permission: User},
  {username: "Dave", permission: User},
  {username: "Dave", permission: User},
|];

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div>
      <h1 onClick=(event => handleClick(event))>
        (ReasonReact.string(message))
      </h1>
      <ul>
        (
          data
          |> Array.map(item =>
               <li>
                 <div>
                   (ReasonReact.string(item.username))
                   (ReasonReact.string(" - "))
                   (
                     switch (item.permission) {
                     | Admin => ReasonReact.string("Admin")
                     | User => ReasonReact.string("User")
                     | Worker => ReasonReact.string("Worker")
                     }
                   )
                 </div>
                 <div />
               </li>
             )
          |> ReasonReact.array
        )
      </ul>
    </div>,
};