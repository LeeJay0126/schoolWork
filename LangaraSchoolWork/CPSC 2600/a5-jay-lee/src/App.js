import { Route, Switch } from "react-router-dom";

import Home from "./components/Home";
import Error from "./components/Error";
import About from "./components/About";
import Navbar from "./components/Navbar";

function App(){

  return (
    
    <div className="todoapp stack-large">
      <Navbar />
      <Switch>
        <Route path="/" component={Home} exact />
        <Route path="/about" component={About} />
        <Route component={Error} />
      </Switch>
    </div>
  );
}

export default App;
