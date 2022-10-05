import { Link } from "react-router-dom";
function Navbar() {

    return (
        <nav className="homeNav">
            <Link to="/">Home</Link>
            <span>|</span>
            <Link to="/about">About</Link>
        </nav>
    );
}

export default Navbar;